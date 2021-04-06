#include "pugixml.hpp"
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

std::vector<string> split(const string& str, const string& delim) {
  std::vector<string> tokens;
  size_t prev = 0, pos = 0;
  do
  {
    pos = str.find(delim, prev);
    if (pos == string::npos) pos = str.length();
    string token = str.substr(prev, pos-prev);
    if (!token.empty()) tokens.push_back(token);
    prev = pos + delim.length();
  }
  while (pos < str.length() && prev < str.length());
  return tokens;
}

class Stop;

struct Route {
  std::string type_of_vehicle_;
  double length;

  std::vector<Stop> stops;

};

struct Stop {
  std::string name_;
  std::string type_of_vehicle_;
  std::string location_;
  std::vector<std::string> routes_;
  double coord_x_, coord_y_;

  [[nodiscard]] double getLength(const Stop& other) const {
    return sqrt((this->coord_x_ - other.coord_x_) * (this->coord_x_ - other.coord_x_) +
                (this->coord_y_ - other.coord_y_) * (this->coord_y_ - other.coord_y_));
  }
};

class Database {
private:
  std::vector<Stop> stops;
  //fixed common code
  std::map<std::string, std::map<std::string, Route>> routes;
  std::map<std::string, int> street_to_count_stops;

public:
  explicit Database(const string& path) {
    pugi::xml_document doc;

    if (!doc.load_file("data.xml")) exit(-1);

    pugi::xml_node tools = doc.child("dataset");

    for (pugi::xml_node stop_node = tools.child("transport_station");
         stop_node;
         stop_node = stop_node.next_sibling("transport_station")) {

      auto name = std::string(stop_node.child_value("the_official_name"));
      auto type_of_vehicle = std::string(stop_node.child_value("type_of_vehicle"));
      auto location = std::string(stop_node.child_value("location"));
      auto routes_split = split(std::string(stop_node.child_value("routes")), ",");

      auto coord_x_and_y = split(std::string(stop_node.child_value("coordinates")), ",");

      auto coord_x = std::stod(coord_x_and_y[0]);
      auto coord_y = std::stod(coord_x_and_y[1]);

      auto object_type = std::string(stop_node.child_value("object_type"));

      if (object_type == "Остановка" && !location.empty()) {
        auto stop = Stop{name, type_of_vehicle, location, routes_split, coord_x, coord_y};
        stops.push_back(stop);
        count_routes(routes[type_of_vehicle], stop);
      }
    }
  }
  static void count_routes(std::map<std::string, Route>& routes, const Stop& stop) {
    for (const std::string& number_route : stop.routes_) {
      if (routes.count(number_route) == 0) {
        routes[number_route] = Route{stop.type_of_vehicle_, 0, std::vector<Stop> {}};
      }
      routes[number_route].stops.push_back(stop);
    }
  }
  static auto getMaximumRoutesByStops(const std::map<std::string, Route>& routes) {
    return *std::max_element(routes.begin(), routes.end(),
                             [](const auto& lhs, const auto& rhs) {
                               return lhs.second.stops.size() <
                                      rhs.second.stops.size();
                              }
                             );
  }
  void printMaximumRoutesByStops() {
    std::cout << "Маршрут с наибольшим количеством остановок по отдельными видам транспорта:\n";
    for (const auto& [type_of_route, number_to_route] : routes) {
      const auto& [number, route] = getMaximumRoutesByStops(routes[type_of_route]);
      std::cout << type_of_route << " №" << number << " остановок -- " << route.stops.size() << '\n';
    }
  }
  static void countLength(std::map<std::string, Route>& routes) {
    for (auto& [_, route] : routes) {
      route.length = 0;
      for (auto it = begin(route.stops); it != prev(end(route.stops)); it++) {
        route.length += it->getLength(*next(it));
      }
      route.length += prev(end(route.stops))->getLength(*begin(route.stops));
    }
  }
  static auto getMaximumRoutesByLength(std::map<std::string, Route>& routes) {
    countLength(routes);
    return *std::max_element(routes.begin(), routes.end(),
                             [](const auto& lhs, const auto& rhs) {
                                 return lhs.second.length <
                                        rhs.second.length;
                                }
                             );
  }
  void printMaximumRoutesByLength() {
    std::cout << "Наиболее длинный маршрут (основывая на координатах) по отдельным видам транспорта\n";
    for (const auto& [type_of_route, number_to_route] : routes) {
      const auto& [number, route] = getMaximumRoutesByLength(routes[type_of_route]);
      std::cout << type_of_route << " №" << number << " остановок -- " << route.length << '\n';
    }
  }
  auto getMaximumStreetByStops() {
    for (const Stop& stop : stops) {
      auto streets = split(stop.location_, ",");
      for (const auto& street : streets) {
        if (street_to_count_stops.count(street) == 0) {
          street_to_count_stops[street] = 0;
        }
        street_to_count_stops[street]++;
      }
    }
    auto res = make_pair(std::string(" "), 0);
    auto& [res_name, res_counter] = res;
    for (const auto& [name, counter] : street_to_count_stops) {
      if (counter > res_counter) {
        res_name = name;
        res_counter = counter;
      }
    }
    return res;
  }
  void printMaximumStreetByStops() {
    const auto& [name, counter] = getMaximumStreetByStops();
    std::cout << "Улицa с наибольшим числом остановок -- "
              << name << " кол-во остановок: "
              << counter << std::endl;
  }
};

int main() {
  setlocale(LC_CTYPE, "rus");

  Database db("data.xml");

  db.printMaximumRoutesByStops();

  db.printMaximumRoutesByLength();

  db.printMaximumStreetByStops();
}