/*
    Website: IEEEXtreme
    Difficulty: Medium
    Language: c++
    Link: https://csacademy.com/ieeextreme-practice/task/333043935273ab966569971859d1835b/
*/


#include <bits/stdc++.h>

using namespace std;

// We can use dijkstra's for the shortest path

 // Function to find the shortest path from node A to node B
 // Using Dijkstra's algorithm.
vector<long long> dijkstraShortestPath(const vector<vector<long long>>& graph, 
    long long A, long long B) {
    long long numVertices = graph.size();
    vector<long long> distance(numVertices, LLONG_MAX);
    vector<long long> parent(numVertices, -1);
    vector<bool> visited(numVertices, false);

    distance[A] = 0;

    // Creates a priority queue to store nodes and their distances
    priority_queue<pair<long long, long long>, 
    vector<pair<long long, long long>>, 
    greater<pair<long long, long long>>> pq;

    pq.push({0, A});

    while (!pq.empty()) {
        long long u = pq.top().second;
        pq.pop();

        if (u == B) break; // Stop early if we have reached node B

        if (visited[u]) continue;

        visited[u] = true;

        for (long long v = 0; v < numVertices; ++v) {
            if (!visited[v] && graph[u][v] != 0 &&
                distance[u] != LLONG_MAX && distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
                parent[v] = u;
                pq.push({distance[v], v});
            }
        }
    }

    // Reconstructs the shortest path to find the indices
    vector<long long> shortestPath;
    long long currentVertex = B;
    while (currentVertex != -1) {
        shortestPath.push_back(currentVertex);
        currentVertex = parent[currentVertex];
    }

    reverse(shortestPath.begin(), shortestPath.end());

    return shortestPath;
}

int main() {
    
    long long n, m;
    cin >> n >> m;

    // Note that although not mentioned, we can safely assume after some testing
    // that there is always a unique shortest path. Otherwise, we'd have
    // to modify Dijkstra to get all the shortest paths using depth first search.

    vector<long long> ids(n);
    // Map from id to index for use later
    unordered_map<long long, long long> cityIndex;
    for(long long i = 0; i < n; i++){
        cin >> ids[i];
        cityIndex[ids[i]] = i;
    }
    
    vector<vector<long long>> graph(n, vector<long long>(n, 0));
    for(long long i = 0; i < m; i++){
        long long x, y, d;
        cin >> x >> y >> d;
        long long indexX = cityIndex[x], indexY = cityIndex[y];
        
        // Since graph is not directed, we change both
        graph[indexX][indexY] = graph[indexY][indexX] = d;
    }
    
    long long maxId = *max_element(ids.begin(), ids.end());
    long long minId = *min_element(ids.begin(), ids.end());
    
    long long maxIndex = cityIndex[maxId], minIndex = cityIndex[minId];
    
    // Shortest path from city with smallest id to largest
    vector<long long> shortestPath 
        = dijkstraShortestPath(graph, minIndex, maxIndex);


    // To speed things up, we can just load in the values of the products
    // of primes from 2 to n where the product only goes on until it exceeds
    // 10^18 (the maximum of k). This will only be around 25 values, 
    // which helps us immensly as it removes the need to calculate the
    // first n primes a costly expenditure.
    // (2 3 5 and 7). We use a python program to generate these.
    /*
        import sympy
        def products_of_primes():
            product = 1
            current_prime = 2
            while True:
                if sympy.isprime(current_prime):
                    product *= current_prime
                    if product > 10**18:
                        print(product, end=",\n")
                        break
                    else:
                        print(product, end=",\n")
                current_prime = sympy.nextprime(current_prime)
        products_of_primes()
    */
    // Note the last value isn't really the next largest prime product
    // after 10^18, but just any number after 10^18, as the former doesn't fit.
    // In this case, it's 10^18 + 5. For the last number in this array only,
    // any number larger than 10^18 will do, as long as it fits in a long long.
    long long primeProducts[] {
        2ll,
        6ll,
        30ll,
        210ll,
        2310ll,
        30030ll,
        510510ll,
        9699690ll,
        223092870ll,
        6469693230ll,
        200560490130ll,
        7420738134810ll,
        304250263527210ll,
        13082761331670030ll,
        614889782588491410ll,
        1000000000000000005ll,
    };
    
    
    // We sort the ids so we can linearly go through them whil increasing
    // prime factors. Only do this for shortest path ids.
    vector<long long> idSorted;
    for (long long i = 0; i < shortestPath.size(); i++) {
        idSorted.push_back(ids[shortestPath[i]]);
    }
    sort(idSorted.begin(), idSorted.end());
    
    // Maximum primes we can multiply and still be under i,
    // which we sum and place here
    long long maxProductNumber{};
    
    for(long long i = 0, index = 0; index < idSorted.size();){

        if(idSorted[index] < 2){
            maxProductNumber += 0;
            index++;
        }
        else if(idSorted[index] >= primeProducts[i]
            && idSorted[index] < primeProducts[i+1]){
            maxProductNumber += i+1;
            index++;
        }
        else{
            i++;
        }
    }
    
    cout << maxProductNumber;
    
    return 0;
}