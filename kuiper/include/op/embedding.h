
#ifndef KUIPER_INCLUDE_OP_EMBEDDING_H_
#define KUIPER_INCLUDE_OP_EMBEDDING_H_
#include <utility>
#include "layer.h"
namespace op {
struct EmbeddingOutput {
  tensor::Tensor input_tokens;
  tensor::Tensor input_embeddings;
  tensor::Tensor input_token_num;
  explicit EmbeddingOutput(tensor::Tensor input_tokens, tensor::Tensor input_embeddings,
                           tensor::Tensor input_token_num)
      : input_tokens(std::move(input_tokens)), // 原始输入token的索引序列
        input_embeddings(std::move(input_embeddings)), // 输入token对应的嵌入向量
        input_token_num(std::move(input_token_num)) {} // 每个样本中有效token的实际数量
};

class EmbeddingLayer : public LayerParam {
 public:
  explicit EmbeddingLayer(base::DeviceType device_type, int32_t dim, int32_t seq_len,
                          int32_t vocab_size);

  base::Status check() const override;

  base::Status forward() override;

 private:
  int32_t dim_ = 0;
  int32_t seq_len_ = 0;
  int32_t vocab_size_ = 0;
};
}  // namespace op
#endif  // KUIPER_INCLUDE_OP_EMBEDDING_H_
