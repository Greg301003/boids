#include "boids.hpp"

#include <cmath>

// definizione operatore somma

Vector2d Vector2d::operator+=(Vector2d const& v) {
  return {this->x + v.x, this->y + v.y};

  // si potrebbe cambiare con
  // x += other.x;
  // y += other.y;
  // return *this;
  //?
}

// sostituisco l con scalar

// definizione operatore prodotto con scalare

Vector2d Vector2d::operator*(double const& scalar) {
  return {x * scalar, y * scalar};
}

// definizione calcolo lunghezza

double Vector2d::length(Vector2d const& v) {
  return {std::sqrt(v.x * v.x + v.y * v.y)};
}

// def distance

double Boid::Distance(Boid const& b1, Boid const& b2) {
  double dx = b1.position_.x - b2.position_.x;
  double dy = b1.position_.y - b2.position_.y;
  return std::sqrt(dx * dx + dy * dy);
}

// def getpos and getvel

Vector2d Boid::GetPosition(Boid const& b) { return b.position_; }

Vector2d Boid::GetVelocity(Boid const& b) { return b.velocity_; }

// constructor
Boid::Boid(Vector2d const& pos, Vector2d const& vel, Vector2d const& acc)
    : position_{pos}, velocity_{vel}{
  // create shape
  shape_.setPointCount(3);
  shape_.setPoint(0, sf::Vector2f(0, 0));
  shape_.setPoint(1, sf::Vector2f(20, 10));
  shape_.setPoint(2, sf::Vector2f(0, 20));
  shape_.setFillColor(sf::Color::Green);
}