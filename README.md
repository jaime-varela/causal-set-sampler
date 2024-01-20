# causal-set-sampler
A causal set point sampler for arbitrary metrics

# Description

Obtain causal set point sprinking using imporance sampling for arbitrary metrics.

# Methodology

Given the determinant of the metric $\sqrt{-g}$, a coordinate bound, and the sprinkling density $\rho$ the software does the following:

1. Integrates $\sqrt{-g}$ over the domain to optain the coordinat sampling distribution $p(x^{\mu}) = \sqrt{-g(x^{\mu})} / \int \sqrt{-g}$, where the integration is over the provided bounds.  Currently only connected regions are supported.
2. Find the global maximum of $c=p(x^{\mu})$ using optimlib
3. Perform importance sampling using $c$

Eventually this program may have MCMC as an available sampling option.

# Requirements

1. Optimlib
2. Steven Jhonsons [Integration library](https://github.com/stevengj/cubature) .  A git-clone into the root dir of this repository is needed