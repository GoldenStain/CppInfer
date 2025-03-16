#include <glog/logging.h>
#include <gtest/gtest.h>
#include <filesystem>

int main(int argc, char* argv[]) {
  FLAGS_log_dir = "./log/";
  FLAGS_alsologtostderr = true;
  const std::string log_dir = FLAGS_log_dir;
  if (!std::filesystem::exists(log_dir)) {
    if (!std::filesystem::create_directories(log_dir)) {
      std::cerr << "Failed to create the log directory: " << log_dir << std::endl;
      return -1;
    }
  }
  testing::InitGoogleTest(&argc, argv);
  google::InitGoogleLogging("Kuiper");

  LOG(INFO) << "Start Test...\n";
  return RUN_ALL_TESTS();
}