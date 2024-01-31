#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
	std::string type;

	is >> type;
	if (type == "NEW_BUS") {
		size_t size;

		q.type = QueryType::NewBus;
		is >> q.bus >> size;
		q.stops.resize(size);
		for (auto &i : q.stops) 
			std::cin >> i;

	} else if (type == "BUSES_FOR_STOP") {
		q.type = QueryType::BusesForStop;
		is >> q.stop;
	} else if (type == "STOPS_FOR_BUS") {
		q.type = QueryType::StopsForBus;
		is >> q.bus;
	} else if (type == "ALL_BUSES") {
		q.type = QueryType::AllBuses;
	}
  return is;
}

struct BusesForStopResponse {
	bool no_stop;
	std::vector<std::string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
	if (r.no_stop) {
		os << "No stop";
	} else {
		for (const std::string &bus : r.buses)
			 os << bus << ' ';
	}
  return os;
}

struct StopsForBusResponse {
	std::vector<std::string> stops;
	std::vector<std::vector<std::string>> stops_to_buses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	if (r.stops.size() == 0) {
		os << "No bus";
	} else {
		for (size_t i = 0; i < r.stops.size(); ++i) {
			os << "Stop " << r.stops[i] << ":";
			for (const auto &j : r.stops_to_buses[i])
				os << ' ' << j;
			if (i + 1 != r.stops.size())
				os << std::endl;
		}
	}
  return os;
}

struct AllBusesResponse {
	std::map<std::string, std::vector<std::string>> buses_to_stops;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
	if (r.buses_to_stops.size() == 0) 
		os << "No buses";
	else {
		for (const auto &[bus, stops] : r.buses_to_stops) {
			os << "Bus " << bus << ":";
			for (const auto &stop : stops)
				os << ' ' << stop;
			if ((--r.buses_to_stops.end())->first != bus)
				os << std::endl;
		}
	}
  return os;
}

class BusManager {
	std::map<std::string, std::vector<std::string>> buses_to_stops, stops_to_buses;

public:
  void AddBus(const string& bus, const vector<string>& stops) {
		buses_to_stops[bus] = stops;
		for (const auto &stop : stops) {
			stops_to_buses[stop].push_back(bus);
		}
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
		BusesForStopResponse ans;

    if (stops_to_buses.count(stop) == 0) {
			ans.no_stop = true;
    } else {
			ans.no_stop = false;
			ans.buses = stops_to_buses.at(stop);
    }
		return (ans);
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
		StopsForBusResponse ans;
		
		if (buses_to_stops.count(bus) == 0)  {
			ans.stops.resize(0);
			return (ans);
		}
		ans.stops = buses_to_stops.at(bus);
		ans.stops_to_buses.resize(ans.stops.size());
		for (size_t i = 0; i < ans.stops.size(); ++i) {
			if (stops_to_buses.at(ans.stops[i]).size() == 1)
				ans.stops_to_buses[i].push_back("no interchange");
			else  {
				for (const string& other_bus : stops_to_buses.at(ans.stops[i])) {
        	if (bus != other_bus) {
						ans.stops_to_buses[i].push_back(other_bus);
          }
				}
			}
		}
		return (ans);
  }

  AllBusesResponse GetAllBuses() const {
		AllBusesResponse ans;

		ans.buses_to_stops = buses_to_stops;
		return (ans);
  }
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
