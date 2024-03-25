
include("metric_volume_form.jl")

export schwarchild_spherical

mutable struct schwarchild_spherical <: metric_volume_form
    dimension::Int
end

function schwarchild_spherical()
    return schwarchild_spherical(4)
end

function metric_volume_density(coordinates::AbstractVector{T},metric_density::schwarchild_spherical) where {T<:Real}
    r = coordinates[2]
    theta = coordinates[3]
    # Fixme: check to see if the formula below is correct for all dimensions
    return r*r*sin(theta)
end

function metric_volume_density_jacobian(coordinates::AbstractVector{T},metric_density::schwarchild_spherical) where {T<:Real}
    r = coordinates[2]
    theta = coordinates[3]
    derivative = zeros(Float64,metric_density.dimension)
    derivative[2] = 2.0*r*sin(theta)
    derivative[3] = r*r*cos(theta)
    return derivative
end