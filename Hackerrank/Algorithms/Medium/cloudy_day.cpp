/*
    Website: Hackerank
    Difficulty: Medium
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/cloudy-day/problem
*/


#include <bits/stdc++.h>

using namespace std;

// Struct for a location, be it town or cloud start or cloud end
struct Location{
    long long location;
    short type;  // 0 for town, 1 for cloud start, 2 for cloud end
    long long population;   // Only set if type is town

    // Index of town or cloud, used for identification 
    // (see where a cloud's start ends).
    // We don't care about the index if type is town
    long long index;    
};

int main(){

    // Note that two towns can have the same location
    long long n;
    cin >> n;
    vector<long long> population;
    vector<Location> locations;

    for(long long i = 0; i < n; i++){
        long long g;
        cin >> g;
        population.push_back(g);
    }
    
    // Since some towns may be in the same location, we can make the algorithm
    // more efficient by merging them into a single town with combined 
    // populations. We can do it with a hashmap from location to population.
    // Note that we don't care about the index here since this is a town,
    // not a cloud (we keep it 0).
    unordered_map<long long, long long> cloudsMap; 

    for(long long i = 0; i < n; i++){
        long long location;
        cin >> location;
        // Type is town
        cloudsMap[location] += population[i];
    }
    for(auto i = cloudsMap.begin(); i != cloudsMap.end(); i++){
        // i->first is location, second is population, we don't care for index,
        // and type is town
        locations.push_back({i->first, 0, i->second, 0});
    }

    long long m;
    cin >> m;

    vector<long long> cloudLocation(m);
    
    for(long long i = 0; i < m; i++){
        cin >> cloudLocation[i];
    }
    for(long long i = 0; i < m; i++){
        long long range;
        cin >> range;

        // Type is cloud start, no population
        locations.push_back({cloudLocation[i] - range, 1, 0, i});
        // Type is cloud end, no population
        locations.push_back({cloudLocation[i] + range, 2, 0, i});
    }

    

    // We then sort the locations vector according to the locations.
    // If two elements have the same location, we always prioritize having
    // the start cloud types first, and the end clouds last, so they wrap
    // all towns underneath them (like parantheses).

    sort(locations.begin(), locations.end(),
        [](const Location& a, const Location& b) -> bool{
            if(a.location < b.location) return true;
            else if(a.location > b.location) return false;
            // If both are equal
            else{
                // Cloud start should always be first
                // Cloud end should be last
                if(a.type == 1 || b.type == 2) return true;
                else if (a.type == 2 || b.type == 1) return false;
                // In this case, both are towns, so we don't care
                else return true;
            }
        }
    );

    // We now implement a stack like algorithm for processing parnatheses
    // to see which clouds wrap which towns.
    // This won't use a stack, because unlike parantheses and brackets,
    // just because a cloud starts first doesn't mean it ends last.
    // So we only keep track of how may are open and how many are closed
    // using a vector.
    
    // Using each cloud's index, we can set the population that it covers
    // as the value of each element. Note that we only do that if it is
    // the only cloud currently covering it (we know how many clouds are
    // above us at any point).
    vector<long long> cloudPopulations (m, 0);

    // We use am unordered set to keep tracks of clouds above us for O(1) 
    // addition and removal since we dont care for order and all indeces are
    // unique.
    unordered_set<long long> clouds;
    

    // This value is incremented by the population if we are not under
    // any clouds.
    long long populationNotUnderCloud{};

    for(long long i = 0; i < locations.size(); i++){
        if(locations[i].type == 1){
            clouds.insert(locations[i].index);
        }
        else if (locations[i].type == 2){
            clouds.erase(locations[i].index);
        }
        // If we have a town
        else{
            // And only one cloud above us
            if(clouds.size() == 1){
                // Since the set has one element, we use an iterator
                long long index = *(clouds.begin());
                cloudPopulations[index] += locations[i].population;
            }
            // No clouds above us
            else if (clouds.size() == 0){
                populationNotUnderCloud += locations[i].population;
            }
        }
    }

    // We then get the maximum number of people under any single cloud
    long long maximum = *max_element(cloudPopulations.begin(),
        cloudPopulations.end()); 
        
    // Then we sum that number along with the populations of people under no
    // clouds for the people that won't be under clouds once we destory
    // the cloud whose death frees the most people
    cout << (maximum + populationNotUnderCloud);
    
    return 0;
}
