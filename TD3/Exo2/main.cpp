#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSumBruteForce(const vector<int>& nums, int target) {
    vector<int> v(2,-1);
    int ind1 = -1, ind2, k = 0;
    for (const auto& i : nums) {
        ind1++;
        ind2 = -1;
        for (const auto& j : nums) {
            ind2++;
            if( i + j == target && ind1!=ind2 ){
                v.resize(k+2);
                v[k] = ind1;
                v[k+1] = ind2;
                k+=2;
                return v;
            }
        }
    }
    return v;
}


vector<int> twoSumOptimal(const vector<int>& nums, int target) {
    unordered_map<int, int> numMap;  // Pour stocker les valeurs et leurs indices
    vector<int> result(2, -1);       // Vecteur pour stocker les deux indices, initialisé à -1
    
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];  // Calculer le complément nécessaire
        
        // Vérifier si le complément est déjà dans la map
        if (numMap.find(complement) != numMap.end()) {
            result[0] = numMap[complement];  // Indice du complément
            result[1] = i;                   // Indice courant
            return result;
        }
        
        // Ajouter l'élément courant à la map
        numMap[nums[i]] = i;
    }
    
    return result;  // Retourner {-1, -1} si aucune solution n'est trouvée
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> indicesBruteForce = twoSumBruteForce(nums, target);
    cout << "Brute Force Solution: ["
         << indicesBruteForce[0] << ", "
         << indicesBruteForce[1] << "]" << endl;

    vector<int> indicesOptimal = twoSumOptimal(nums, target);
    cout << "Optimal Solution: ["
         << indicesOptimal[0] << ", "
         << indicesOptimal[1] << "]" << endl;

    return 0;
}
