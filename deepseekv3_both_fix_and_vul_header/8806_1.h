#include <sys/types.h>
#include <signal.h>
#include <poll.h>
#include <linux/fs.h>

struct snd_pcm_substream;
struct snd_pcm_runtime;
struct snd_timer;

#define CONFIG_SND_PCM_TIMER
#define PCM_RUNTIME_CHECK(substream) (0)

struct snd_pcm_substream {
    struct snd_pcm_runtime *runtime;
#ifdef CONFIG_SND_PCM_TIMER
    struct snd_timer *timer;
    int timer_running;
#endif
};

struct snd_pcm_runtime {
    struct fasync_struct *fasync;
};

void snd_pcm_stream_lock_irqsave(struct snd_pcm_substream *substream, unsigned long flags);
void snd_pcm_stream_unlock_irqrestore(struct snd_pcm_substream *substream, unsigned long flags);
int snd_pcm_running(struct snd_pcm_substream *substream);
int snd_pcm_update_hw_ptr0(struct snd_pcm_substream *substream, int in_interrupt);
void snd_timer_interrupt(struct snd_timer *timer, unsigned long ticks);
void kill_fasync(struct fasync_struct **fp, int sig, int band);