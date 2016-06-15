#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <memory>
#include <string>


namespace movelib {
  struct Data
  {
      int a{42};
  };

  class Mover
  {
    public:
      virtual std::unique_ptr<Data> takeIt()
      {
        return std::make_unique<Data>();
      }
      virtual std::unique_ptr<Data> takeIt(std::string const& a)
      {
        return std::make_unique<Data>();
      }
      virtual std::unique_ptr<Data> takeIt(std::string const& a, std::string const& b, std::string const& c)
      {
        return std::make_unique<Data>();
      }
  };
} // namespace movelib


class MoverMock
  : public movelib::Mover
{
  public:
    MOCK_METHOD0(takeIt, std::unique_ptr<movelib::Data>());
    MOCK_METHOD1(takeIt, std::unique_ptr<movelib::Data>(std::string const&));
    MOCK_METHOD3(takeIt, std::unique_ptr<movelib::Data>(std::string const&, std::string const&, std::string const&));
};


TEST(MoverMockUser, instantiate_mover_mock)
{
  MoverMock _mock;
}
