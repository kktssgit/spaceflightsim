#pragma once
// math lib
/* what to add
Vec2 / Vec3 / Vec4 (templated on float/double — sims want double for orbital-scale precision)
- operators: + - * / (vec-vec, vec-scalar), unary -, += -= *= /=, == !=
- dot, cross (Vec3 only)
- length, lengthSquared, normalize, normalized
- distance, distanceSquared
- lerp(a, b, t)
- min, max, clamp (component-wise)
- reflect, project, angleBetween

Mat3 / Mat4
- identity, zero
- operator* (matmat, matvec)
- transpose, determinant, inverse
- translate, scale, rotate(axis, angle) (Mat4)
- perspective, ortho, lookAt (Mat4, if you're rendering)
- fromQuaternion, toQuaternion

Quaternion (essential for spacecraft attitude — avoids gimbal lock)
- identity
- operator* (quatquat, quatvec3 for rotating a vector)
- conjugate, inverse, normalize, length
- fromAxisAngle, fromEuler, toEuler
- slerp, nlerp
- toMat3/toMat4

Scalar utils (namespace-level, not a struct)
- lerp, clamp, remap
- degToRad, radToDeg
- wrapAngle (normalize to [-π, π] — you'll want this constantly for attitude/orbit angles)
- isNearlyEqual(a, b, epsilon)

Transform struct (composes the above — very useful for rigid bodies)
- members: Vec3 position, Quaternion rotation, Vec3 scale
- toMat4, operator* (compose transforms), inverse
- transformPoint, transformDirection

Orbital mechanics — this is what actually makes it a spaceflight sim rather than a generic engine, and it doesn't belong in generic Vec/Quat code:
- solveKeplerEquation(meanAnomaly, eccentricity) (Newton iteration)
- orbitalElementsToStateVector(a, e, i, Ω, ω, ν) → position/velocity
- stateVectorToOrbitalElements(pos, vel, mu)
- vis-viva(r, a, mu) → speed
- hohmannTransfer(r1, r2, mu) → Δv
*/