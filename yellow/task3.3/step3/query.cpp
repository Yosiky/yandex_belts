#include "query.h"

std::istream& operator >> (std::istream& is, Query& q) {
	std::string type;

	is >> type;
	if (type == "NEW_BUS") {
		size_t size;

		q.type = QueryType::NewBus;
		is >> q.bus >> size;
		q.stops.resize(size);
		for (auto &i : q.stops) 
			is >> i;

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


