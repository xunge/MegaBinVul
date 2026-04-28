struct AsyncReadPixelsCompletedQuery {
    bool completed_;
    int complete_result_;
    void Complete();
};

int MarkAsCompleted(int);