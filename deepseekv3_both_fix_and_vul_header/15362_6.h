#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <memory>

typedef int32_t status_t;
#define OK 0
#define NO_ERROR 0
#define NO_MEMORY -12

class String8 {
public:
    String8(const char16_t*);
};

template<typename T>
class Vector {
public:
    void add(const T&);
};

template<typename T>
class sp {
public:
    sp(T*);
    T* operator->();
};

class IBinder {
public:
    static constexpr int FIRST_CALL_TRANSACTION = 1;
};

class unique_fd {
public:
    int release();
    int get() const;
};

class Parcel {
public:
    int readFileDescriptor() const;
    status_t readUniqueFileDescriptor(unique_fd*) const;
    int32_t readInt32() const;
    bool dataAvail() const;
    String8 readString16() const;
    IBinder* readStrongBinder() const;
};

class IInterface {
public:
    class Descriptor;
};

template<typename INTERFACE>
class BnInterface : public IBinder, public INTERFACE {
};

class IShellCallback : public IInterface {
public:
    static IShellCallback* asInterface(IBinder*);
};

class IResultReceiver : public IInterface {
public:
    static IResultReceiver* asInterface(IBinder*);
    void send(status_t);
};

class BnIncidentManager : public IBinder {
public:
    virtual status_t onTransact(uint32_t, const Parcel&, Parcel*, uint32_t);
};

class IncidentService : public BnIncidentManager {
public:
    status_t onTransact(uint32_t, const Parcel&, Parcel*, uint32_t) override;
    status_t command(FILE*, FILE*, FILE*, const Vector<String8>&);
};

enum {
    SHELL_COMMAND_TRANSACTION = IBinder::FIRST_CALL_TRANSACTION
};