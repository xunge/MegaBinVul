#include <memory>
#include <list>
#include <cassert>

#define DCHECK assert

enum class TargetProperty {
  SCROLL_OFFSET
};

class AnimationCurve {
public:
  virtual ~AnimationCurve() {}
  virtual std::unique_ptr<AnimationCurve> Clone() const = 0;
};

struct AnimationEvent {
  TargetProperty target_property;
  double monotonic_time;
  double animation_start_time;
  AnimationCurve* curve;
};

class ElementAnimations {
public:
  void NotifyAnimationTakeover(const AnimationEvent& event);
protected:
  void NotifyPlayersAnimationTakeover(double monotonic_time,
                                     TargetProperty target_property,
                                     double animation_start_time,
                                     std::unique_ptr<AnimationCurve> animation_curve);
  bool IsEmpty() const;
  std::list<int>* players_list_;
};