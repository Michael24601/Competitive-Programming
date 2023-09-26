#include <bits/stdc++.h>

using namespace std;

// Removes vector elements from vector 1 in vector 2
void removeElements(vector<long long>& v1, vector<long long>& v2) {
    v1.erase(std::remove_if(v1.begin(), v1.end(), [&v2](long long value) {
        return std::find(v2.begin(), v2.end(), value) != v2.end();
    }), v1.end());
}

// Town
struct town{
    long long population;
    long long location;
};

int main(){
    
    // Note that two towns can have the same location
    long long n;
    cin >> n;
    vector<long long> population(n);
    vector<town> towns(n);
    
    for(long long i = 0; i < n; i++){
        cin >> population[i];
    }
    for(long long i = 0; i < n; i++){
        long long location;
        cin >> location;
        towns[i] = {population[i], location};
    }
    
    long long m;
    cin >> m;
    
    vector<long long> cloudLocation(m);
    for(long long i = 0; i < m; i++){
        cin >> cloudLocation[i];
    }
    
    // Maps cloud start/end location to the indexes of clouds that 
    // start and end there.
    // We want an ordered map, so that they are sorted by the keys.
    map<long long, vector<long long>> cloudStart;
    map<long long, vector<long long>> cloudEnd;
    for(long long i = 0; i < m; i++){
        long long range;
        cin >> range;

        if (!cloudStart.count(cloudLocation[i] - range)) {
            // If the key doesn't exist, create it with an empty vector
            cloudStart[cloudLocation[i] - range] = vector<long long>();
        }
        if (!cloudEnd.count(cloudLocation[i] + range)) {
            // If the key doesn't exist, create it with an empty vector
            cloudEnd[cloudLocation[i] + range] = vector<long long>();
        }

        cloudStart[cloudLocation[i] - range].push_back(i);
        cloudEnd[cloudLocation[i] + range].push_back(i);
    }

    // We then keep track in a location map, of the indeces of clouds that
    // are above each location.
    map<long long, vector<long long>> cloudsCovering;
    // Current clouds above a certain location
    vector<long long> currentCloudsAbove;
    
    // We check the locations starting at the first cloud start and
    // ending at the last cloud end. We go over each location 
    // by moving along the two maps cloudEnd and cloudStart.
    for(auto i = cloudStart.begin(), j = cloudEnd.begin(); 
        i != cloudStart.end() || j != cloudEnd.end(); ) {

        // Since i's location is smaller, this location has cloud starts
        // (Or j is done being processed, as in the ending locations are done)
        if(j == cloudEnd.end() 
            || (i != cloudStart.end() && i->first < j->first)){
            if(!i->second.empty()){
                currentCloudsAbove.insert(currentCloudsAbove.end(),
                i->second.begin(),  i->second.end());
            }

            cloudsCovering[i->first] = currentCloudsAbove;
            i++;
        }
        // Since j's location is smaller, this location has cloud ends
        // (Or i is done being processed, as in the starting locations are done)
        else if (i == cloudStart.end() 
            || (j != cloudEnd.end() && i->first >= j->first)){
            if(!j->second.empty()){
                removeElements(currentCloudsAbove, j->second);
            }
            cloudsCovering[j->first] = currentCloudsAbove;
            j++;
        }
    }

    
    // We then loop over the towns and check how many clouds are above them.
    // We add their populations to a vector that keeps track of how many
    // people a cloud covers as long as it is the only cloud that covers them.
    // And we also at the same time sum the populations under no clouds at all.
    // Note that the cloudCoverings map doesn't contain all locations,
    // we have to checl if the town locations fits between one location in the
    // map and the next (it only contains the locations where the clouds
    // above change (add or remove clouds ot both)).
    // However, we need to sort the towns by location first.

    sort(towns.begin(), towns.end(), [](const town& a, const town& b) {
        return a.location < b.location;
    });
    
    long long peopleUnderNoClouds{};
    vector<long long> cloudPopulations(m, 0);

    long long townIndex = 0;
    for(auto i = cloudsCovering.begin(); townIndex < towns.size() 
        && i != cloudsCovering.end(); i++){

        auto nextCloudIterator = next(i);

        // This means we reached the last "cloud state" and all the rest
        // of the towns will have the same cloud state, so we just
        // loop through them all and set them
        if(nextCloudIterator == cloudsCovering.end()){
            
            while(townIndex < towns.size()){

                // If town has no cloud above it
                if(i->second.size() == 0){
                    peopleUnderNoClouds += towns[townIndex].population;
                }
                // If town has one single cloud above it
                else if(i->second.size() == 1){
                    cloudPopulations[i->second[0]] 
                        += towns[townIndex].population;
                }
                townIndex++;
            }
        }
        else{
            // Else loop over them until we need to change cloud state again
            while(townIndex < towns.size() 
                && towns[townIndex].location >= i->first 
                && towns[townIndex].location < next(i)->first) {

                // If town has no cloud above it
                if(i->second.size() == 0){
                    peopleUnderNoClouds += towns[townIndex].population;
                }
                // If town has one single cloud above it
                else if(i->second.size() == 1){
                    cloudPopulations[i->second[0]] 
                        += towns[townIndex].population;
                }

                townIndex++;
            }
        }
    }
    

    // We then get the maximum number of people under any single cloud
    long long maximum = *max_element(cloudPopulations.begin(),
        cloudPopulations.end()); 
        
    // Then we sum that number along with the populations of people under no
    // clouds for the people that won't be under clouds once we destory
    // the cloud whose death frees the most people
    cout << (maximum + peopleUnderNoClouds);
    
    
    return 0;
}
