# causal-set-sampler
A causal set point sampler for, in principle, arbitrary metrics

# Description

Obtain causal set point sprinking using rejection sampling for arbitrary metrics.  Currently the notebook 'causal_set_tester' has an example with schwarchild.

# Methodology

Given the determinant of the metric $\sqrt{-g}$, a coordinate bound, and the sprinkling density $\rho$ we do the following:

1. Integrate $\sqrt{-g}$ over the domain to obtain the coordinate sampling distribution $p(x^{\mu}) = \sqrt{-g(x^{\mu})} / \int \sqrt{-g}$, where the integration is over the provided bounds.  Currently only connected regions are supported.
2. Find the global maximum of $c=p(x^{\mu}) + \epsilon_p$ using an optimization library
3. Perform rejection sampling using $c$


# Requirements

1. [Cubature package](https://juliahub.com/ui/Packages/General/HCubature)
2. Optim.jl


