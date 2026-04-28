#include <utility>

struct MLIRContext {};
struct Operation {
  struct Error {
    Error& operator<<(const char*) { return *this; }
  };
  Error emitError() { return Error(); }
};

struct RewritePatternSet {
  RewritePatternSet(MLIRContext*) {}
  template<typename... T> void add(MLIRContext*) {}
  template<typename... T> void add(MLIRContext*, bool) {}
};

template<typename T> struct LogicalResult {
  bool failed() { return false; }
};

namespace TF {
  struct Conv2DOp {};
  struct DepthwiseConv2dNativeOp {};
  struct ReshapeOp {
    static void getCanonicalizationPatterns(RewritePatternSet&, MLIRContext*) {}
  };
  struct ConvertTFEinsumOp {};
  static void PopulateUnrollTfBatchMatMul(MLIRContext*, RewritePatternSet&) {}
};

namespace TFL {
  static void populateWithGenerated(RewritePatternSet&) {}
};

template<typename T> struct ConvertTFDilatedConvOp {};
struct FusedBatchNormV3Pat {};
struct RemoveIdentity {};
struct ConvertTFBroadcastTo {};
struct ConvertTFStridedSlice {};
struct ConvertRfftToRfft2d {};
struct ConvertTFConv2D {};
struct ConvertTFDepthwiseConv2dNative {};

bool use_fake_quant_num_bits_;
bool unfold_batch_matmul_;
bool allow_bf16_and_f16_type_legalization_;

struct PrepareTFPass {
  MLIRContext& getContext();
  Operation& getOperation();
  void signalPassFailure();
  void runOnOperation();
};

LogicalResult<bool> ValidateOp(Operation&) { return {}; }
LogicalResult<bool> ConvertTf2XlaOps(Operation&, MLIRContext*) { return {}; }
LogicalResult<bool> ConvertFakeQuantOps(Operation&, MLIRContext*, bool) { return {}; }
void applyPatternsAndFoldGreedily(Operation&, RewritePatternSet&&) {}

template<typename T>
bool failed(T&& t) { return t.failed(); }