#include "gamepadstate.h"

GamepadState::GamepadState():
    m_left_stick_x(0),
    m_left_stick_y(0),
    m_right_stick_x(0),
    m_right_stick_y(0),
    m_left_trigger(0),
    m_right_trigger(0)
{

}

signed char GamepadState::left_stick_x() const
{
    return m_left_stick_x;
}

void GamepadState::setLeft_stick_x(signed char left_stick_x)
{
    m_left_stick_x = left_stick_x;
}

signed char GamepadState::left_stick_y() const
{
    return m_left_stick_y;
}

void GamepadState::setLeft_stick_y(signed char left_stick_y)
{
    m_left_stick_y = left_stick_y;
}

signed char GamepadState::right_stick_x() const
{
    return m_right_stick_x;
}

void GamepadState::setRight_stick_x(signed char right_stick_x)
{
    m_right_stick_x = right_stick_x;
}

signed char GamepadState::right_stick_y() const
{
    return m_right_stick_y;
}

void GamepadState::setRight_stick_y(signed char right_stick_y)
{
    m_right_stick_y = right_stick_y;
}

signed char GamepadState::left_trigger() const
{
    return m_left_trigger;
}

void GamepadState::setLeft_trigger(signed char left_trigger)
{
    m_left_trigger = left_trigger;
}

signed char GamepadState::right_trigger() const
{
    return m_right_trigger;
}

void GamepadState::setRight_trigger(signed char right_trigger)
{
    m_right_trigger = right_trigger;
}
