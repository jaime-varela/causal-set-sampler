using Distributions

export random_sampler_uniform


"""
Take a sample from a distribution, specified by a pdf, over a given
range using rejection sampling.  Uses a uniform distribution as
proposal distribution.

Input:

- pdf -- the pdf to sample (needn't be normalized)
- coordinate_lower_bound -- an array with the pdf coordinate lower bounds
- coordinate_upper_bound -- an array with the pdf coordinate upper bounds
- max_density -- the maximal value of the distribution (or an upper bound estimate)
- ntries=10^7 -- max number of Monte Carlo steps

https://en.wikipedia.org/wiki/Rejection_sampling

Note, ApproxFun can be used for 1D sampling too and may be much faster.
"""

function random_sampler_uniform(pdf::Function,
                                coordinate_lower_bound::AbstractVector{T},
                                coordinate_upper_bound::AbstractVector{T},
                                max_density::Real,
                                ntries::Int64 = 10^2) where {T<:Real}
    
    dr = (coordinate_upper_bound-coordinate_lower_bound)
    ndims = size(dr)[1]

    # use Uniform(range) as distribution g(x)
    @inbounds for i=1:ntries
        xt = dr.* rand(ndims)+coordinate_lower_bound
        if pdf(xt)/max_density >= rand()
            return xt
        end
    end
    error("No sample found.")
end
