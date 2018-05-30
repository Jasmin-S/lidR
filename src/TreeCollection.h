#ifndef TREECOLLECTION_H
#define TREECOLLECTION_H

#include "TreeSegment.h"

using namespace arma;

class TreeCollection
{
  public:
    TreeCollection();
    TreeCollection(TreeSegment &t);
    TreeCollection(const TreeCollection &t);
    ~TreeCollection();

    void addTree(TreeSegment t);
    void updateTree(int &treeID, PointXYZ &pt);

    void searchID_usingArea(std::vector<int> &knnTreeID, PointXYZ &pointToSort, int &resultID, double &areaValue, boost::geometry::model::ring<point_t> &hull);
    void searchID_usingDist(std::vector<int> &knnTreeID, PointXYZ &pointToSort, int &resultID, double &distValue);

    void getSizeCriteria(int k);
    void getOrientationCriteria();
    void getRegularityCriteria();
    void getCircularityCriteria();
    double calculateTreeScores(int k);

    void remove_tree_with_less_than_3_points();

    Rcpp::List to_R();

    unsigned int nbTree;
    //std::vector<double> individualTreeSize;
    std::vector<TreeSegment>treeStorage;
    std::vector<int> idTreeStorage;
};

#endif //TREECOLLECTION_H