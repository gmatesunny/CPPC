#include <iostream>
#include <vector>

#define BUCKETS   599       /* A decently large enough prime number */

using namespace std;

typedef struct data {
    string wordsworth;      /* key */
    int count;              /* number of occurance of this key */
} data_t;

static int hashFn(string val)
{
    int sum = 0;

    for (unsigned int i = 0; i < val.size(); i++) {
        /* abba is different from baba */
        sum += static_cast<char>(val[i]) * (i + 1);
    }
    return sum % BUCKETS;
}

/*
 * @details:    insert the key-value (wordsworth-and it's num of occurance) pair
 *              in the appropriatehash bucket.
 * @param:      vv: reference to the 2d matrix
 * @param:      wordsworth: key for the hash function
 * @note:       Store the key as well in the datastore to implement hashing
 *              with chaining.
 */
static void insert(vector<vector<data_t> > &vv, string wordsworth)
{
    data_t node;
    int idx = hashFn(wordsworth);

    node.wordsworth = wordsworth;
    node.count = 1;
    
    /* first item in the bucket */
    if (vv[idx].size() == 0) {
        vv[idx].push_back(node);
        return;
    }

    /* compare the key and if found, increment the count */
    for (unsigned int i = 0; i < vv[idx].size(); i++) {
        if (wordsworth == vv[idx][i].wordsworth) {
            vv[idx][i].count++;
            return;
        }
    }

    /* a different word fell into this same bucket */
    vv[idx].push_back(node);
}

static int getcount(vector<vector<data_t> > &vv, string wordsworth)
{
    int idx = hashFn(wordsworth);
    for (unsigned int i = 0; i < vv[idx].size(); i++) {
        if (wordsworth == vv[idx][i].wordsworth) {
            return vv[idx][i].count;
        }
    }

    return 0;
}

/*
 * @details:    Entry point and test routine
 */
int main(void)
{
    int N;
    cout << "Enter number of entries" << endl;
    cin >> N;
    
    vector<vector<data_t> > vv(BUCKETS);
    int i;
    string words;

    cout << "Enter each word" << endl;
    for (i = 0; i < N; i++) {
        cin >> words;
        insert(vv, words);
    }

    int q;
    cout << "Enter number of queries" << endl; 
    cin >> q;

    cout << "Enter the word whose number of occurances, you seek" << endl;
    for (i = 0; i < q; i++) {
        cin >> words;
        cout << getcount(vv, words) << endl;
    }
    
    return 0;
}
