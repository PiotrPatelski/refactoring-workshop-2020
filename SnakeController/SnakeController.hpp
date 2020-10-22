#pragma once

#include <list>
#include <memory>

#include "IEventHandler.hpp"
#include "SnakeInterface.hpp"

class Event;
class IPort;

namespace Snake
{
struct ConfigurationError : std::logic_error
{
    ConfigurationError();
};

struct UnexpectedEventException : std::runtime_error
{
    UnexpectedEventException();
};

struct Segment
{
public:
    int x;
    int y;
    int ttl;
    void updatePosition(Segment newSegment, Direction currentDirection)
    {
        x = newSegment.x + ((currentDirection & 0b01) ? (currentDirection & 0b10) ? 1 : -1 : 0);;
        y = newSegment.y + (not (currentDirection & 0b01) ? (currentDirection & 0b10) ? 1 : -1 : 0);;
        ttl = newSegment.ttl;
    }
    bool isEqualPosition(Segment otherSegment)
    {
        return (x==otherSegment.x and y==otherSegment.y);
    }
};

class Controller : public IEventHandler
{

public:
    Controller(IPort& p_displayPort, IPort& p_foodPort, IPort& p_scorePort, std::string const& p_config);

    Controller(Controller const& p_rhs) = delete;
    Controller& operator=(Controller const& p_rhs) = delete;

    void receive(std::unique_ptr<Event> e) override;
    void checkIfLost(Segment newSegment);
private:
    bool lost{false};

    IPort& m_displayPort;
    IPort& m_foodPort;
    IPort& m_scorePort;

    std::pair<int, int> m_mapDimension;
    std::pair<int, int> m_foodPosition;

    Direction m_currentDirection;
    std::list<Segment> m_segments;
};

} // namespace Snake
