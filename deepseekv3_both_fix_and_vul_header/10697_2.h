#include <stdint.h>

#define JQS_wTail 0
#define JQS_wHead 4
#define JQS_wSize 8
#define MIDQ_DATA_BUFF 0
#define MSNDMIDI_MODE_BIT_INPUT_TRIGGER 0

typedef uint16_t u16;

struct snd_msndmidi {
    struct {
        void *mappedbase;
        void *MIDQ;
    } *dev;
    unsigned long mode;
    int input_lock;
    void *substream_input;
};

static inline u16 readw(void *addr) { return 0; }
static inline void writew(u16 val, void *addr) {}
static inline void spin_lock_irqsave(int *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(int *lock, unsigned long flags) {}
static inline int test_bit(int nr, unsigned long *addr) { return 0; }
static inline void snd_rawmidi_receive(void *substream, unsigned char *data, int count) {}