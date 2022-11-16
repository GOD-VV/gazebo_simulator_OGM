/*
 * @Author: gw mc15406@umac.mo
 * @Date: 2022-11-12 11:25:14
 * @LastEditors: gw
 * @LastEditTime: 2022-11-12 15:55:11
 * @Description: University of Macau IMRL
 */


#ifndef GRID_MAP_H
#define GRID_MAP_H

#include <Eigen/Core>
#include <opencv2/opencv.hpp>
#include <nav_msgs/OccupancyGrid.h>

class GridMap{
    public:
        GridMap(const int& size_x,const int& size_y,const int& init_x,const int& init_y,const double& cell_size );
        bool setGridBel(const double& x,const double& y,const double& bel);
        bool getGridBel(const double& x,const double& y,double& bel);
        bool setGridLogBel(const double& x,const double& y,const double& log_bel);
        bool getGridLogBel(const double& x,const double& y,double& log_bel);
        double getCellSize();

        void toRosOccGridMap(const std::string& frame_id, nav_msgs::OccupancyGrid& occ_grid);
        cv::Mat toCvMat();
        void saveMap(const std::string& img_dir,const std::string& cfg_dir);
        void loadMap(const std::string& img_dir,const std::string& cfg_dir);
    
    private:
        bool getIdx(const double& x,const double& y,Eigen::Vector2i& idx);
    
    private:
        int size_x_,size_y_,init_x_,init_y_;
        double cell_size_;
        Eigen::MatrixXd bel_data_;
        Eigen::MatrixXd m_one_,m_show_;

};

#endif
