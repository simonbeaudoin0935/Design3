#include "detecteurcarres.h"

#include <vector>
#include <math.h>


DetecteurCarres::DetecteurCarres():
    thresh(200),
    N(5)
{

}

bool DetecteurCarres::detecterCarres(cv::Mat& p_matSource, int p_nombreCarresMinimum, int p_nombreCarresMaximum, int p_airMinimum, int p_airMaximum, std::vector< std::vector< cv::Point> >&  p_vecteurDeCarres)
{
    p_vecteurDeCarres.clear();

//s    Mat pyr, timg, gray0(image.size(), CV_8U), gray;

    // down-scale and upscale the image to filter out the noise
    //pyrDown(image, pyr, Size(image.cols/2, image.rows/2));
    //pyrUp(pyr, timg, image.size());


    // blur will enhance edge detection
    cv::Mat timg(p_matSource);
    //blur( image, timg, Size(2,2) );
    //medianBlur(image, timg, 3);
    cv::GaussianBlur(p_matSource, timg, cv::Size(3,3), 1.5, 1.5);
    cv::Mat gray0(timg.size(), CV_8U), gray;

    std::vector<std::vector<cv::Point> > contours;

    // find squares in every color plane of the image
    for( int c = 0; c < 3; c++ )
    {
        int ch[] = {c, 0};
        cv::mixChannels(&timg, 1, &gray0, 1, ch, 1);

        // try several threshold levels
        for( int l = 0; l < N; l++ )
        {
            // hack: use Canny instead of zero threshold level.
            // Canny helps to catch squares with gradient shading
            if( l == 0 )
            {
                // apply Canny. Take the upper threshold from slider
                // and set the lower to 0 (which forces edges merging)
                cv::Canny(gray0, gray, 5, thresh, 5);
                // dilate canny output to remove potential
                // holes between edge segments
                cv::dilate(gray, gray, cv::Mat(), cv::Point(-1,-1),8);
            }
            else
            {
                // apply threshold if l!=0:
                //     tgray(x,y) = gray(x,y) < (l+1)*255/N ? 255 : 0
                gray = gray0 >= (l+1)*255/N;
            }

            // find contours and store them all as a list
            cv::findContours(gray, contours, cv::RETR_LIST, cv::CHAIN_APPROX_SIMPLE);

            std::vector<cv::Point> approx;

            // test each contour
            for( size_t i = 0; i < contours.size(); i++ )
            {
                // approximate contour with accuracy proportional
                // to the contour perimeter
                cv::approxPolyDP(cv::Mat(contours[i]), approx, cv::arcLength(cv::Mat(contours[i]), true)*0.02, true);

                // square contours should have 4 vertices after approximation
                // relatively large area (to filter out noisy contours)
                // and be convex.
                // Note: absolute value of an area is used because
                // area may be positive or negative - in accordance with the
                // contour orientation
                if( approx.size() == 4 &&
                    fabs(contourArea(cv::Mat(approx))) < p_airMaximum &&
                    fabs(contourArea(cv::Mat(approx))) > p_airMinimum &&
                    isContourConvex(cv::Mat(approx)) )
                {
                    double maxCosine = 0;

                    for( int j = 2; j < 5; j++ )
                    {
                        // find the maximum cosine of the angle between joint edges
                        double cosine = fabs(angle(approx[j%4], approx[j-2], approx[j-1]));
                        maxCosine = MAX(maxCosine, cosine);
                    }

                    // if cosines of all angles are small
                    // (all angles are ~90 degree) then write quandrange
                    // vertices to resultant sequence
                    if( maxCosine < 0.01 )
                        p_vecteurDeCarres.push_back(approx);
                }
            }
        }
    }

  //  while(contours.size() > 1){
 //       contours.pop_back();
 //   }
    return true;
}






// helper function:
// finds a cosine of angle between vectors
// from pt0->pt1 and from pt0->pt2
double DetecteurCarres::angle(cv::Point pt1, cv::Point pt2, cv::Point pt0 )
{
    double dx1 = pt1.x - pt0.x;
    double dy1 = pt1.y - pt0.y;
    double dx2 = pt2.x - pt0.x;
    double dy2 = pt2.y - pt0.y;
    return (dx1*dx2 + dy1*dy2)/sqrt((dx1*dx1 + dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10);
}




// the function draws all the squares in the image


void DetecteurCarres::drawSquare( cv::Mat& image, const std::vector< std::vector< cv::Point> >& squares )
{
    for( size_t i = 0; i < squares.size(); i++ )
    {
        const cv::Point* p = &squares[i][0];

        int n = (int)squares[i].size();
        //dont detect the border
        if (p-> x > 3 && p->y > 3)
          cv::polylines(image, &p, &n, 1, true, cv::Scalar(255,0,0), 1, cv::LINE_AA);
    }


}


