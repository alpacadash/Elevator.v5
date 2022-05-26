//Programmer: Younghyun Kwon
//Programmer ID: 1651849
#include "Floor.h"
#include "Rider.h"
#include "Panel.h"
#include "Building.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include <climits>

const char* const Floor::UP = "Up";
const char* const Floor::DOWN = "Down";
int Floor::TOP = INT_MIN; // defined in climits
int Floor::BOTTOM = INT_MAX; // also in climits

Floor::Floor(const int elevation, const char* const name, const char* const label)
:name(name), label(label), elevation(elevation)
{
  panel.addButton(UP);
  panel.addButton(DOWN);
  if (TOP < elevation) TOP = elevation;
  if (elevation < BOTTOM) BOTTOM = elevation;
}

void Floor::addRider(const Rider& r)
{
  if(r.goingUp)
  {
    this->upRiders.push(r);
    panel.press(UP);
  }
  else if(r.goingDown)
  {
    this->downRiders.push(r);
    panel.press(DOWN);
  }
}

Rider Floor::removeUpRider()
{
  if(this->upRiders.empty())
  {
    throw "No UpRider!";
  }

  Rider local = this->upRiders.front();
  this->upRiders.pop();

  return local;
}

Rider Floor::removeDownRider()
{
  if(this->downRiders.empty())
  {
    throw "No DownRider!";
  }

  Rider local = this->downRiders.front();
  this->downRiders.pop();

  return local;
}

ostream& operator<<(ostream& out, const Floor& floor)
{
  out.width(3);
  out << floor.label;
  out.width(15);
  out << floor.name << " at";
  out.width(6);
  out << floor.elevation;
  out << "\" Up/Down:";
  out.width(4);
  out << floor.upRiders.size() << "/";
  out.width(4);
  out.setf(ios::left);
  out << floor.downRiders.size() << " Button: " << floor.panel;
  out.unsetf(ios::left);
  return out;
}
