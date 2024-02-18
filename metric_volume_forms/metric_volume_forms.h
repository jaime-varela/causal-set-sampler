#pragma once
#include <Eigen/Dense>
// Abstract class for space-time metric volume forms

namespace causalSetSampler
{
    class metric_volume_forms
    {
    protected:
        /* data */
        int dimension;
        bool is_jacobian_defined = false;
    public:
        metric_volume_forms(/* args */);
        ~metric_volume_forms();

        virtual double differential_volume(const Eigen::VectorXd& coordinates) = 0;

        virtual Eigen::VectorXd differential_volume_derivative(const Eigen::VectorXd& coordinates) {
            Eigen::VectorXd emptyVector; // Create an empty VectorXd
            return emptyVector;
        };

        double optimization_function(const Eigen::VectorXd& x, Eigen::VectorXd* grad_out, void* opt_data)
        {
            //FIXME figure out if this is right
            double u;
            if (grad_out && this->is_jacobian_defined) {
                *grad_out = this->differential_volume_derivative(x);
            } else {
                u = this->differential_volume(x);
            }

            return u;
    }

    };
    
    metric_volume_forms::metric_volume_forms(/* args */)
    {
    }
    
    metric_volume_forms::~metric_volume_forms()
    {
    }
    
    
}