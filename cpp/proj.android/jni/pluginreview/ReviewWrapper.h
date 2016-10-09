
#ifndef _PLUGIN_REVIEW_WRAPPER_H_
#define _PLUGIN_REVIEW_WRAPPER_H_

#include "PluginReview.h"
#include "CocosMacros.h"
#include "json98.h"

#define TAG               "Review"
#define VERSION           "v1.0"
#define REVIEW_IOS_VERSION      "ios: v08.21.2015"
#define REVIEW_ANDROID_VERSION  "android: v08.21.2015"
NS_COCOS_BEGIN

class ReviewWrapper {
public:
    static ReviewWrapper* getInstance();

    virtual bool init(const char* jsonconfig = 0) = 0;
    virtual void setListener(ReviewListener* listener) = 0;
    virtual ReviewListener* getListener() = 0;
    virtual void removeListener() = 0;

    /*
     * Set customized title for alert view.
     */
    virtual void setCustomPromptTitle(const std::string& title)=0;

    /*
     * Set customized message for alert view.
     */
    virtual void setCustomPromptMessage(const std::string& message)=0;

    /*
     * Set customized cancel button title for alert view.
     */
    virtual void setCustomPromptCancelButtonTitle(const std::string& cancelTitle)=0;

    /*
     * Set customized rate button title for alert view.
     */
    virtual void setCustomPromptRateButtonTitle(const std::string& rateTitle)=0;

    /*
     * Set customized rate later button title for alert view.
     */
    virtual void setCustomPromptRateLaterButtonTitle(const std::string& rateLaterTitle)=0;

    virtual bool tryToShowPrompt()=0;
    virtual bool forceToShowPrompt(bool displayRateLaterButton)=0;
    virtual void userDidSignificantEvent(bool canPromptForRating)=0;
    virtual void rate()=0;
    virtual bool isInit()=0;
};

class ReviewWrapperDisabled : public ReviewWrapper {
public:

    bool init(const char* jsonconfig = 0) { return false; }
    void setListener(ReviewListener* listener) {}
    ReviewListener* getListener() { return NULL; }
    void removeListener() {}
    void setCustomPromptTitle(const std::string& title) {}
    void setCustomPromptMessage(const std::string& message) {}
    void setCustomPromptCancelButtonTitle(const std::string& cancelTitle) {}
    void setCustomPromptRateButtonTitle(const std::string& rateTitle) {}
    void setCustomPromptRateLaterButtonTitle(const std::string& rateLaterTitle) {}
    bool tryToShowPrompt() { return false; }
    bool forceToShowPrompt(bool displayRateLaterButton) { return false; }
    void userDidSignificantEvent(bool canPromptForRating) {}
    void rate() {}
    bool isInit() { return false; }
};

class ReviewWrapperEnabled : public ReviewWrapper{
public:
    ReviewWrapperEnabled();
    bool init(const char* jsonconfig = 0);
    void setListener(ReviewListener* listener);
    ReviewListener* getListener();
    void removeListener();
    void setCustomPromptTitle(const std::string& title);
    void setCustomPromptMessage(const std::string& message);
    void setCustomPromptCancelButtonTitle(const std::string& cancelTitle);
    void setCustomPromptRateButtonTitle(const std::string& rateTitle);
    void setCustomPromptRateLaterButtonTitle(const std::string& rateLaterTitle);
    bool tryToShowPrompt();
    bool forceToShowPrompt(bool displayRateLaterButton);
    void userDidSignificantEvent(bool canPromptForRating);
    void rate();
    bool isInit() { return haveInit; }

protected:
    bool nativeConfigure(const Json& config);
    const char* nativeSDKVersion();

    ReviewListener* _listener = nullptr;
    bool haveInit;
};

NS_COCOS_END

#endif
