
%group(handles);
%override;

namespace QuantLibAddin {

    class RelinkableHandle {
    public:
        void linkTo(const std::string &objectID2);
    };

    class RelinkableHandleYieldTermStructure {
    public:
        %generate(c#, RelinkableHandleYieldTermStructure);
        %generate(countify, RelinkableHandleYieldTermStructure);
        // attach processor RelinkableHandleProcessor to ctor RelinkableHandleYieldTermStructure.
        %processor(RelinkableHandleYieldTermStructure, RelinkableHandleProcessor);
        // NB: The parameter below must be called "CurrentLink" because there
        // is code which updates a property with that name in the value object.
        RelinkableHandleYieldTermStructure(const std::string &CurrentLink) {}
    };

    class RelinkableHandleQuote {
    public:
        // attach processor RelinkableHandleProcessor to ctor RelinkableHandleQuote.
        %processor(RelinkableHandleQuote, RelinkableHandleProcessor);
        // NB: The parameter below must be called "CurrentLink" because there
        // is code which updates a property with that name in the value object.
        RelinkableHandleQuote(const std::string &CurrentLink) {}
    };
}

