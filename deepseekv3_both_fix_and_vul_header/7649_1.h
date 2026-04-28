#include <memory>
#include <vector>

namespace Eigen {
template<typename T, int Rows, int Cols> 
class Matrix {
public:
    T operator[](unsigned int i) const { return T(); }
    bool hasNaN() const { return false; }
    T& operator[](unsigned int i) { static T t; return t; }
};
typedef Matrix<double, -1, 1> VectorXd;
}

namespace ompl {
namespace base {
class State {
public:
    virtual ~State() = default;
};

class StateSpace {
public:
    virtual ~StateSpace() = default;
    virtual double* getValueAddressAtIndex(State* state, unsigned int index) const = 0;
};

typedef std::shared_ptr<StateSpace> StateSpacePtr;

class SpaceInformation {
public:
    virtual ~SpaceInformation() = default;
    virtual State* allocState() const = 0;
    virtual void copyState(State* destination, const State* source) const = 0;
    virtual double distance(const State* state1, const State* state2) const = 0;
    virtual const StateSpacePtr& getStateSpace() const = 0;
    virtual bool checkMotion(const State* s1, const State* s2) const = 0;
    virtual void freeState(State* state) const = 0;
};

typedef std::shared_ptr<SpaceInformation> SpaceInformationPtr;
}

namespace geometric {
template<typename T>
class NearestNeighbors {
public:
    virtual ~NearestNeighbors() = default;
    virtual void add(const T& data) = 0;
};

class VFRRT {
public:
    class Motion {
    public:
        base::State* state;
        Motion* parent;
        Motion() : state(nullptr), parent(nullptr) {}
        Motion(const base::SpaceInformationPtr& si) : state(si->allocState()), parent(nullptr) {}
        ~Motion() = default;
    };

    Motion* extendTree(Motion* m, base::State* rstate, const Eigen::VectorXd& v);

private:
    base::SpaceInformationPtr si_;
    std::shared_ptr<NearestNeighbors<Motion*>> nn_;
    unsigned int vfdim_;
    double maxDistance_;
    unsigned int inefficientCount_;
    void updateExplorationEfficiency(Motion* motion) {}
};

}
}