#ifndef art__unicode__reader_hxx_
#define art__unicode__reader_hxx_

#include <cstdint>
#include <stdexcept>

namespace art::unicode
{

  /// Abstract reader.
  ///
  class reader_t
  {
  public:
    /// Destructor.
    ///
    virtual
    ~reader_t() noexcept;

    std::uint8_t
    advance();

    virtual
    bool
    at_end() const = 0;

    virtual
    uint8_t
    get() const = 0;

    virtual
    void
    next() = 0;

  protected:
    /// Constructor.
    ///
    reader_t();

    /// Copy-construction is prohibited.
    ///
    reader_t(reader_t const&) = delete;

    /// Move-construction is prohibited.
    ///
    reader_t(reader_t&&) = delete;

    /// Copy-assignment is prohibited.
    ///
    reader_t&
    operator=(reader_t const&) = delete;

    /// Move-assignment is prohibited.
    ///
    reader_t&
    operator=(reader_t&&) = delete;

  };

  template<typename I, typename E = I>
  class iterator_reader_t
    : public reader_t
  {
  public:
    using input_iterator = I;
    using end_iterator = E;

    iterator_reader_t(input_iterator input, end_iterator end)
      : _current{input},
        _end{end}
    {}

    bool
    at_end() const override
    {
      return _current == _end;
    }

    uint8_t
    get() const override
    {
      if (at_end()) {
        throw std::logic_error{"iterator at end"};
      }

      return *_current;
    }

    void
    next() override
    {
      if (at_end()) {
        throw std::logic_error{"iterator at end"};
      }

      ++_current;
    }

  private:
    input_iterator _current;
    end_iterator const _end;

  };

} // namespace art::unicode

#endif
