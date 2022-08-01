struct buf {
  int flags;
  int valid;   // has data been read from disk?
  int disk;    // does disk "own" buf?, 一致性
  uint dev;
  uint blockno;
  struct sleeplock lock;
  uint refcnt;
  struct buf *prev; // LRU cache list
  struct buf *next;
  uchar data[BSIZE];
};


#define B_BUSY 0x1
#define B_VALID 0x2
#define B_DIRTY 0x4