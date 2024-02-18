
#include "metric_volume_forms.h"
// Schwarchild metric

namespace causalSetSampler
{
    class schwarchild_spherical : private metric_volume_forms {
 
public:
        schwarchild_spherical();

        double differential_volume(const Eigen::VectorXd& coordinates) override;

        Eigen::VectorXd differential_volume_derivative(const Eigen::VectorXd& coordinates) override;
    
};
}