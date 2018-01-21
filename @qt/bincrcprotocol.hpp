#ifndef BINCRCPROTOCOL_H
#define BINCRCPROTOCOL_H
#include <QByteArray>
#include <functional>
#include <amlinterface.hpp>

namespace aml {
namespace protocols {

class BinCRCProtocolPrivate;
class BinCRCProtocol
{
    //Q_PROPERTY(int crcErrorCount READ crcErrorCount NOTIFY crcErrorCountChanged)
public:
    BinCRCProtocol();
    ~BinCRCProtocol();

    aml::sinkfunction downlookingSink();
    void connectDownlookingSource(aml::sinkfunction toLowerSink);

    aml::sinkfunction uplookingSink();
    void connectUplookingSource(aml::sinkfunction toUpperSink);

private:
    BinCRCProtocolPrivate * const d_ptr;
    Q_DECLARE_PRIVATE(BinCRCProtocol)
};

} // protocols
} // aml
#endif // BINCRCPROTOCOL_H
