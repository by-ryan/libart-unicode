#include <art/unicode/reader.hxx>

#include <art/validation/main.hxx>

#include <string>

VALIDATION_TEST(test_XYZ)
{
  std::string str{"XYZ"};

  art::unicode::iterator_reader_t reader{
    str.begin(),
    str.end()
  };

  VALIDATION_ASSERT_FALSE(reader.at_end());

  auto b1 = reader.get();
  reader.next();

  VALIDATION_ASSERT_FALSE(reader.at_end());

  auto b2 = reader.get();
  reader.next();

  VALIDATION_ASSERT_FALSE(reader.at_end());

  auto b3 = reader.get();
  reader.next();

  VALIDATION_ASSERT_TRUE(reader.at_end());

  VALIDATION_ASSERT_EQUAL(b1, 'X');
  VALIDATION_ASSERT_EQUAL(b2, 'Y');
  VALIDATION_ASSERT_EQUAL(b3, 'Z');
}

int
main(int argc, char* argv[])
{
  return art::validation::main(argc, argv);
}
