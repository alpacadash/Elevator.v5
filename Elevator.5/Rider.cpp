//Programmer: Younghyun Kwon
//Programmer ID: 1651849
#include "Rider.h"
#include "Building.h"

#include <iostream>
using namespace std;

Rider::Rider(int from,int to)
: from(from), to(to),
goingUp(Building::floors[to] > Building::floors[from] ? true : false ),
goingDown(Building::floors[to] < Building::floors[from] ? true : false )
{
}

Rider& Rider::operator=(const Rider& rider)
{
  Rider& host = *this;
  if(this != &rider)
  {
    const_cast<int&>(host.from) = rider.from;
    const_cast<int&>(host.to) = rider.to;
    const_cast<bool&>(host.goingUp) = rider.goingUp;
    const_cast<bool&>(host.goingDown) = rider.goingDown;
  }
  return host;
}
