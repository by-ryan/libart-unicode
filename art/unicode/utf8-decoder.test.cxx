#include <art/unicode/reader.hxx>
#include <art/unicode/utf8-decoder.hxx>

#include <art/validation/main.hxx>

#include <string>

using namespace art::unicode;

static
uint32_t
decode_one(std::string const& str)
{
  iterator_reader_t reader{str.begin(), str.end()};
  utf8_decoder_t decoder{reader};

  return decoder.decode();
}

VALIDATION_TEST(test_1)
{
  std::string const encoded_0{ "\x00", 1 };
  std::string const encoded_1{ "\x7f", 1 };

  auto decoded_0 = decode_one(encoded_0);
  auto decoded_1 = decode_one(encoded_1);

  VALIDATION_ASSERT_EQUAL(decoded_0, 0U);
  VALIDATION_ASSERT_EQUAL(decoded_1, 0x7fU);
}

VALIDATION_TEST(test_2)
{
  std::string const encoded_0{ "\xc2\x80" };
  std::string const encoded_1{ "\xdf\xbf" };

  auto decoded_0 = decode_one(encoded_0);
  auto decoded_1 = decode_one(encoded_1);

  VALIDATION_ASSERT_EQUAL(decoded_0, 0x80U);
  VALIDATION_ASSERT_EQUAL(decoded_1, 0x7ffU);
}

VALIDATION_TEST(test_3)
{
  std::string const encoded_0{ "\xe0\xa0\x80" };
  std::string const encoded_1{ "\xef\xbf\xbf" };

  auto decoded_0 = decode_one(encoded_0);
  auto decoded_1 = decode_one(encoded_1);

  VALIDATION_ASSERT_EQUAL(decoded_0, 0x800U);
  VALIDATION_ASSERT_EQUAL(decoded_1, 0xffffU);
}

VALIDATION_TEST(test_4)
{
  std::string const encoded_0{ "\xf0\x90\x80\x80" };
  std::string const encoded_1{ "\xf4\x8f\xbf\xbf" };

  auto decoded_0 = decode_one(encoded_0);
  auto decoded_1 = decode_one(encoded_1);

  VALIDATION_ASSERT_EQUAL(decoded_0, 0x10000U);
  VALIDATION_ASSERT_EQUAL(decoded_1, 0x10ffffU);
}

VALIDATION_TEST(overlong)
{
  std::string const encoded{"\xc0\xaf"};
  auto decoded = decode_one(encoded);
  VALIDATION_ASSERT_EQUAL(decoded, 0xFFFDUL);
}

int
main(int argc, char* argv[])
{
  return art::validation::main(argc, argv);
}
