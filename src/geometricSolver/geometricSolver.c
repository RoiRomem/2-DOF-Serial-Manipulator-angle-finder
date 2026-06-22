#include "geometricSolver.h"
#include <math.h>

// output error tracking: 0,0 out of reach
anglePair solve(target *t) {
  double x = t->targetPos.x;
  double y = t->targetPos.y;
  double distSq = x * x + y * y;
  double dist = sqrt(distSq);

  if (dist > (t->limbLength1 + t->limbLength2) ||
      dist < fabsf(t->limbLength1 - t->limbLength2)) {
    return (anglePair){0, 0};
  }

  double cosTheta2 =
      (pow(t->limbLength1, 2) + pow(t->limbLength2, 2) - distSq) /
      (2.0 * t->limbLength1 * t->limbLength2);

  cosTheta2 = fmax(-1.0, fmin(1.0, cosTheta2));

  double theta2 = M_PI - acos(cosTheta2);

  double theta1 =
      atan2(y, x) - atan2(t->limbLength2 * sin(theta2),
                          t->limbLength1 + t->limbLength2 * cos(theta2));

  return (anglePair){(angle){theta1}, (angle){theta2}};
}
