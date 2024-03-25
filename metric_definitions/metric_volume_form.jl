export metric_volume_form
export metric_volume_density

abstract type metric_volume_form end


function metric_volume_density(coordinates::AbstractVector{T},sqrt_g::metric_volume_form) where {T<:Real}
    return 0
end


function metric_volume_density_jacobian(coordinates::AbstractVector{T},sqrt_g::metric_volume_form) where {T<:Real}
    return 0
end