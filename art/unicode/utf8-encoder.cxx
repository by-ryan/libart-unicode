#include <art/unicode/utf8-encoder.hxx>

namespace art::unicode
{

  utf8_encoder_t::
  utf8_encoder_t(writer_t& writer)
    : _writer{writer}
  {}

  void
  utf8_encoder_t::
  encode(uint32_t codepoint)
  {
    // 1 byte.
    //
    if (codepoint <= 0x7f) {
      _writer.write(codepoint);
      return;
    }

    // 2 bytes.
    //
    if (codepoint <= 0x7FF) {
      _writer.write(0b11000000 | ((codepoint >> 6) & 0b00011111));
      _writer.write(0b10000000 | (codepoint & 0b00111111));
      return;
    }

    // 3 bytes.
    //
    if (codepoint <= 0xFFFF) {
      _writer.write(0b11100000 | ((codepoint >> 12) & 0b00001111));
      _writer.write(0b10000000 | ((codepoint >> 6) & 0b00111111));
      _writer.write(0b10000000 | (codepoint & 0b00111111));
      return;
    }

    // 4 bytes.
    //
    if (codepoint <= 0x10FFFF) {
      _writer.write(0b11110000 | ((codepoint >> 18) & 0b00000111));
      _writer.write(0b10000000 | ((codepoint >> 12) & 0b00111111));
      _writer.write(0b10000000 | ((codepoint >> 6) & 0b00111111));
      _writer.write(0b10000000 | (codepoint & 0b00111111));
      return;
    }

    // fixme: throw something else.
    //
    throw 0;
  }

} // namespace art::unicode
