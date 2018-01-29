#ifndef GAMEPADSTATE_H
#define GAMEPADSTATE_H


class GamepadState
{
public:
    GamepadState();

    signed char left_stick_x() const;
    void setLeft_stick_x(signed char left_stick_x);

    signed char left_stick_y() const;
    void setLeft_stick_y(signed char left_stick_y);

    signed char right_stick_x() const;
    void setRight_stick_x(signed char right_stick_x);

    signed char right_stick_y() const;
    void setRight_stick_y(signed char right_stick_y);

    signed char left_trigger() const;
    void setLeft_trigger(signed char left_trigger);

    signed char right_trigger() const;
    void setRight_trigger(signed char right_trigger);

private:
    signed char m_left_stick_x;
    signed char m_left_stick_y;

    signed char m_right_stick_x;
    signed char m_right_stick_y;

    signed char m_left_trigger;
    signed char m_right_trigger;

    //TODO: add the rest later
};

#endif // GAMEPADSTATE_H
