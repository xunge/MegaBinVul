#include <string.h>

#define SNDRV_RAWMIDI_INFO_DUPLEX  (1 << 0)
#define SNDRV_RAWMIDI_INFO_OUTPUT   (1 << 1)
#define SNDRV_RAWMIDI_INFO_INPUT    (1 << 2)
#define SNDRV_RAWMIDI_STREAM_OUTPUT 0
#define SNDRV_RAWMIDI_STREAM_INPUT  1

struct snd_card {
    struct snd_card *card;
};

struct snd_rawmidi {
    char name[32];
    unsigned int info_flags;
    void *private_data;
};

struct snd_rawmidi_ops {
    // Placeholder for MIDI operations
};

struct snd_usb_caiaqdev {
    struct snd_card chip;  // Changed from pointer to direct struct
    char *product_name;
    struct {
        unsigned int num_midi_out;
        unsigned int num_midi_in;
    } spec;
    struct snd_rawmidi *rmidi;
};

extern int snd_rawmidi_new(struct snd_card *card, char *name, int device,
                          unsigned int output_count, unsigned int input_count,
                          struct snd_rawmidi **rmidi);
extern void snd_rawmidi_set_ops(struct snd_rawmidi *rmidi, int stream,
                               struct snd_rawmidi_ops *ops);

struct snd_rawmidi_ops snd_usb_caiaq_midi_output;
struct snd_rawmidi_ops snd_usb_caiaq_midi_input;

// Helper function to access card member
static inline struct snd_card *get_card_ptr(struct snd_usb_caiaqdev *dev)
{
    return &dev->chip;
}