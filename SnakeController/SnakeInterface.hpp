#pragma once

#include <cstdint>
#include <Event.hpp>


enum Direction
{
    Direction_UP    = 0b00,
    Direction_DOWN  = 0b10,
    Direction_LEFT  = 0b01,
    Direction_RIGHT = 0b11
};

struct DirectionInd : public Event
{
    //static constexpr std::uint32_t MESSAGE_ID = 0x10;
    
    Direction direction;
};


struct TimeoutInd : public Event
{
    //static constexpr std::uint32_t MESSAGE_ID = 0x20;
};

enum Cell
{
    Cell_FREE,
    Cell_FOOD,
    Cell_SNAKE
};

struct DisplayInd : public Event
{
    //static constexpr std::uint32_t MESSAGE_ID = 0x30;

    int x;
    int y;
    Cell value;
};

struct FoodInd : public Event
{
    //static constexpr std::uint32_t MESSAGE_ID = 0x40;

    int x;
    int y;
};

struct FoodReq : public Event
{
    //static constexpr std::uint32_t MESSAGE_ID = 0x41;
};

struct FoodResp : public Event
{
    //static constexpr std::uint32_t MESSAGE_ID = 0x42;

    int x;
    int y;
};

struct ScoreInd : public Event
{
    //static constexpr std::uint32_t MESSAGE_ID = 0x70;
};

struct LooseInd : public Event
{
    //static constexpr std::uint32_t MESSAGE_ID = 0x71;
};

 // namespace Snake
