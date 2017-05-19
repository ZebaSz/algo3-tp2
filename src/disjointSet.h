#ifndef ALGO3_TP2_DISJOINTSET_H
#define ALGO3_TP2_DISJOINTSET_H

/**
 * An implementation of a disjoint-set data structure with path compression
 */
class disjointSet {
public:
    /**
     * Constructor
     *
     * @param size of the set
     */
    disjointSet(int);

    /**
     * Destructor
     */
    ~disjointSet();

    /**
     * Gets the count of disjoint subsets in the set
     * @return the amount of disjoint subsets
     */
    int size() const;

    /**
     * Finds the root of a member, compressing the path if possible
     * @return the root of a member
     */
    int find(int);

    /**
     * Checks if two members belong to the same disjoint subset
     * @return true if they members are connected, false otherwise
     */
    int connected(int, int);

    /**
     * Joins the disjoint subsets of two members
     */
    void join(int, int);

private:
    int count;
    int* id;
};

#endif //ALGO3_TP2_DISJOINTSET_H
