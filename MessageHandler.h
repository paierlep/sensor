#ifndef MESSAGE_HANDLER_H
#define MESSAGE_HANDLER_H

/**
 * MessageHandler
 *
 * A very simple class to handle the json upload
 * currently only jsons are used as payload
 * and only http requests are possible
 */
class MessageHandler
{
  public:
    MessageHandler(String baseUrl);
    void sendJson(String json);
  private:
    String m_baseUrl;
};

#endif
