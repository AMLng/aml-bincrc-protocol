#include "bincrcprotocol.h"

namespace aml {
namespace protocols {

class BinCRCProtocolPrivate
{
public:
    void downlookingSink(const QByteArray &block);
    void uplookingSink(const QByteArray &block);

    aml::sinkfunction upperSink;
    aml::sinkfunction lowerSink;
};

} // protocols
} // aml

using namespace aml::protocols;

void BinCRCProtocolPrivate::downlookingSink(const QByteArray &block)
{
    upperSink(block.chopped(1));
}

void BinCRCProtocolPrivate::uplookingSink(const QByteArray &block)
{
    QByteArray modified = QByteArray("X").append(block);
    lowerSink(modified);
}

BinCRCProtocol::BinCRCProtocol() : d_ptr(new BinCRCProtocolPrivate)
{

}

BinCRCProtocol::~BinCRCProtocol()
{
    Q_D(BinCRCProtocol);
    delete d;
}

aml::sinkfunction BinCRCProtocol::downlookingSink()
{
    Q_D(BinCRCProtocol);
    return std::bind(&BinCRCProtocolPrivate::downlookingSink, d, std::placeholders::_1);
}

void BinCRCProtocol::connectDownlookingSource(aml::sinkfunction toLowerSink)
{
    Q_D(BinCRCProtocol);
    d->lowerSink = toLowerSink;
}

aml::sinkfunction BinCRCProtocol::uplookingSink()
{
    Q_D(BinCRCProtocol);
    return std::bind(&BinCRCProtocolPrivate::uplookingSink, d, std::placeholders::_1);
}

void BinCRCProtocol::connectUplookingSource(aml::sinkfunction toUpperSink)
{
    Q_D(BinCRCProtocol);
    d->upperSink = toUpperSink;
}
