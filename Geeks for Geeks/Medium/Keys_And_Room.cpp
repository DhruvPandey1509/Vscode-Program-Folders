#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        if (rooms.empty())
            return true;

        unordered_set<int> visited_rooms;

        queue<int> rooms_to_visit;
        rooms_to_visit.push(0);

        while (!rooms_to_visit.empty())
        {
            int curr_room = rooms_to_visit.front();
            rooms_to_visit.pop();

            if (visited_rooms.find(curr_room) == visited_rooms.end())
            {
                visited_rooms.insert(curr_room);
            }

            for (auto k : rooms[curr_room])
            {
                if (visited_rooms.find(k) == visited_rooms.end())
                {
                    rooms_to_visit.push(k);
                }
            }
        }

        return (visited_rooms.size() == rooms.size()) ? true : false;
    }
};