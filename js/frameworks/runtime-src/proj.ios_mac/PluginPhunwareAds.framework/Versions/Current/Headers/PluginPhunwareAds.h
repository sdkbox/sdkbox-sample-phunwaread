/****************************************************************************

 Copyright (c) 2014-2017 SDKBOX Inc

 ****************************************************************************/

#ifndef _PLUGIN_PHUNWAREADS_H_
#define _PLUGIN_PHUNWAREADS_H_

#include <string>
#include <map>

namespace sdkbox {

    class PhunwareAdsListener;
    class PluginPhunwareAds {
    public:

        /**
         *  initialize the plugin instance.
         */
        static bool init();

        /**
         * Set listener to listen for phunware events
         */
        static void setListener(PhunwareAdsListener* listener);

        /**
         * Get the listener
         */
        static PhunwareAdsListener* getListener();

        /**
         * Remove the listener, and can't listen to events anymore
         */
        static void removeListener();

        /**
         * cache ad by specifying ad name, auto cache default.
         */
        static void cache(const std::string& name);

        /*!
         * is the specified ad available?
         */
        static bool isAvailable(const std::string& name);

        /*!
         * show ad by specifying ad name.
         */
        static void show(const std::string& name);

        /*!
         * hide ad by specifying ad name.
         */
        static void hide(const std::string& name);

        /*!
         * set user ID for rewarded video.
         */
        static void setUserID(const std::string& userID);

        /*!
         * get remaining views of rewarded video.
         */
        static int getRemainingViews(const std::string& name);

        /*!
         * set custom data of rewarded video
         */
        static void setCustomData(const std::string& name, const std::map<std::string, std::string>& data);
        };

    class PhunwareAdsListener {
    public:

        /*!
         * there is cached content
         */
        virtual void adLoaded(const std::string& name) {}
        /*!
         * there is error when cache content
         */
        virtual void adFailed(const std::string& name, int errorCode, const std::string& msg) {}
        /*!
         * ad will present
         */
        virtual void adWillPresent(const std::string& name) {}
        /*!
         * ad did present
         */
        virtual void adDidPresent(const std::string& name) {}
        /*!
         * ad will dissmiss
         */
        virtual void adWillDissmiss(const std::string& name) {}
        /*!
         * ad did dismiss
         */
        virtual void adDidDismiss(const std::string& name) {}
        /*!
         * will leave application
         */
        virtual void willLeaveApp(const std::string& name) {}
        /*!
         * reward user with specifying ad name
         */
        virtual void reward(const std::string& name, float amount, const std::string& currency, const std::map<std::string, std::string>& customData) {}

    };
}

#endif
