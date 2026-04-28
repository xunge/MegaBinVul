struct scsi_cmnd;
struct scatterlist;

int sg_copy_from_buffer(struct scatterlist *sgl, unsigned int nents,
                        void *buf, int buflen);
struct scatterlist *scsi_sglist(struct scsi_cmnd *cmd);
unsigned int scsi_sg_count(struct scsi_cmnd *cmd);