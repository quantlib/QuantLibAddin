
%group(quote);
%override;

%insert(quote_addin_cpp) %{
#include <qlo/objmanual_indexes.hpp>
%}

namespace QuantLibAddin {

    bool close(double x, double y);

    class Quote {
      public:
        double value();
        bool isValid();
    };

    class SimpleQuote : public Quote {
      public:
        %generate(c++, SimpleQuote);
        %generate(c#, SimpleQuote);
        %generate(countify, SimpleQuote);
        // NB: The first parameter below must be called "Value" because there
        // is code which updates a property with that name in the value object.
        SimpleQuote(
                    QuantLib::Real Value,
                    QuantLib::Real tickValue);

        %generate(countify, setValue);
        QuantLib::Real setValue(QuantLib::Real Value);
    };

    class ForwardSwapQuote : public Quote {
      public:
        ForwardSwapQuote(const boost::shared_ptr<QuantLib::SwapIndex>& swapIndex,
                         const QuantLib::Handle<QuantLib::Quote>& spread,
                         const QuantLib::Period& fwdStart);
    };

    class LastFixingQuote : public Quote {
      public:
        %generate(countify, LastFixingQuote);
        LastFixingQuote(const boost::shared_ptr<QuantLib::Index>& index);
    };

    class FuturesConvAdjustmentQuote : public Quote {
      public:
        %generate(countify, FuturesConvAdjustmentQuote);
        FuturesConvAdjustmentQuote(const boost::shared_ptr<QuantLib::IborIndex>& index,
                                   const std::string& immCode,
                                   const QuantLib::Handle<QuantLib::Quote>& futuresQuote,
                                   const QuantLib::Handle<QuantLib::Quote>& volatility,
                                   const QuantLib::Handle<QuantLib::Quote>& meanReversion);
    };

     class CompositeQuote : public Quote {
      public:
        %generate(countify, CompositeQuote);
        CompositeQuote(
                    const QuantLib::Handle<QuantLib::Quote>& element1,
                    const QuantLib::Handle<QuantLib::Quote>& element2,
                    const std::string& op);
    };
}

