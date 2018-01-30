# Design3

Le git contient les dossiers suivants :

* Base\_Station\_QT\_Workspace :
    Le code source de la station de base est développé avec [Qt](https://www.qt.io/) que vous pouvez downloader [ici](https://www.qt.io/download). Selectionnez la version open-source. Lors de l'installation, n'oubliez pas, lors de la sélection des components à installer, de expand le noeud 'Qt' et de cocher la case 'Qt 5.10.0', sinon vous n'installerez que l'IDE QtCreator. 

* Motor\_Controller\_SW4STM\_Workspace :
    Le code source du controlleur de moteur est réalisé avec le board STM32F407 Discovery. Le IDE utilisé est System Workbench 4 STM32 (SW4STM32) 

# Procédure pour configurer OpenCV et le faire marcher avec Qt (Linux)

* Télechargez les dépendances de opencv : `sudo apt-get -y install libopencv-dev build-essential cmake git libgtk2.0-dev pkg-config python-dev python-numpy libdc1394-22 libdc1394-22-dev libjpeg-dev libpng12-dev libtiff4-dev libjasper-dev libavcodec-dev libavformat-dev libswscale-dev libxine-dev libgstreamer0.10-dev libgstreamer-plugins-base0.10-dev libv4l-dev libtbb-dev libqt4-dev libfaac-dev libmp3lame-dev libopencore-amrnb-dev libopencore-amrwb-dev libtheora-dev libvorbis-dev libxvidcore-dev x264 v4l-utils unzip`
* Créez un dossier pour télécharger opencv : `mkdir opencv`
* Allez dans ce dossier : `cd opencv`
* Téléchargez les sources de opencv : `wget https://github.com/Itseez/opencv/archive/3.0.0-alpha.zip -O opencv-3.0.0-alpha.zip`
* Dézippez l'archive téléchargée : `unzip opencv-3.0.0-alpha.zip`
* Allez dans le dossier créé : `cd opencv-3.0.0-alpha`
* Créez un dossier pour le build qui suit : `mkdir build`
* Allez dans ce dossier : `cd build`
* Créez les makefiles : `cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D WITH_TBB=ON -D WITH_V4L=ON -D WITH_QT=ON -D WITH_OPENGL=ON ..`
* Compilez tout le shitload : `make -j $(nproc)`
* Enfin installez le tout au bon endroit : `sudo make install`
* Ça y est, opencv est installé convenablement. 

* Dans les fichiers projet .pro dans Qt, ajouter les lignes (déjà présentes dans celui de la base-station) : 
    * `INCLUDEPATH += /usr/local/include` 
    * `LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui`

* Ne pas oubliez d'inclure `#include <opencv2/opencv.hpp>` dans les fichier où vous utilisez opencv

# Procédure pour configurer OpenCV et le faire marcher avec Qt (macOS)

* Une des façons d'installer OpenCV sur Mac OS est via Homebrew, le package manager pour macOS. Si vous n'avez pas downloadé Homwebrew, cliquez [ici](https://brew.sh/index_fr.html). Avec Homebrew, il suffit d'entrer les commandes suivantes dans un terminal: `brew tap homebrew/science brew install opencv3`
* Après avoir installé OpenCV, vous devez indiquer à Qt où trouver pkg-config. La localisation par défaut de pkg-config est /usr/local/bin (vous pouvez le vérifier en entrant `which pkg-config` dans un terminal). Dans l'IDE de Qt, allez dans Project -> Build & Run -> build on Desktop -> Build Environment. Il faut ajouter /usr/local/bin au PATH. Ne pas oubliez le ":" avant l'ajout. Ajoutez une nouvelle variable PKG_CONFIG_PATH. Entrez `find /usr/local -name “opencv.pc”` dans un terminal. Normalement, vous devriez avoir /usr/local/Cellar/opencv/3.4.0_1/lib/pkgconfig/open.cv en output. Copiez uniquement /usr/local/Cellar/opencv/3.4.0_1/lib/pkgconfig/ et apposé cette valeur à la variable PKG_CONFIG_PATH. 


# Procédure pour configurer votre github (Linux)
* Creer un dossier 'Design_3_git' dans Documents.
* Downloader git (si ce n'est pas déjà fait via le script plus haut) : `sudo apt-get install git-all`
* Downloader xclip pour mettre des chose dans le clipboard : `sudo apt-get install xclip`
* Vérifier si vous avez une clé SSH générée : `ls -al ~/.ssh` 
* Sinon générer votre clé SSH : `ssh-keygen -t rsa -b 4096 -C "votre.adresse.email@email.com"`
* Copiez votre clé SSH dans le clipboard : `xclip -sel clip < ~/.ssh/id_rsa.pub`
* Connectez-vous sur github, puis en haut à droite cliquez sur votre photo de profil, puis allez dans settings
* Cliquez sur SSH and GPG keys
* Cliquez sur New SSH Key
* Collez votre clé SSH.
* Indiquez à git votre adresse email : `git config --global user.email "votre.adresse.email@email.com"`
* Indiquez à git votre nom : ` git config --global user.name "Votre Nom"`
* Dans le dossier 'Design_3_git' ouvrez un terminal.
* Clonez le repository : `git clone git@github.com:simonbeaudoin0935/Design3.git`

*Remarques pour macOS*
* apt-get est utilisé pour installer des packages avec Linux. L'équivalent pour Mac est Homebrew.
* Si `xclip -sel clip < ~/.ssh/id_rsa.pub` ne copie pas la clé, essayez d'obtenir la clé publique avec `cat ~/.ssh/id_rsa.pub` puis copiez là.

# Reminder de quelques commandes git utiles 
* Quand vous modifiez la structure, ajoutez ou supprimez des fichiers : `git add .`
* Quand vous voulez commit les changements : `git commit -m "votre commentaire"`
* Enfin : `git push`
* Si tout est chié : `git reset --hard origin/master` ou n'importe quelle autre branche




# Si vous avez des erreurs de compilation pour la Base-Station liées à de librairies manquantes 
* \*\*cannot find -lGL\*\* : `sudo apt-get install libgl1-mesa-dev`
* \*\*cannot find -lpulse : `sudo apt-get install libpulse-dev`





