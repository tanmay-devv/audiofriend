#include<iostream>
#include<string>
#include<curl/curl.h>

int main(void)
{
  CURL *curl;
  CURLcode result;

  curl = curl_easy_init();
  if (curl == NULL) {
    fprintf(stderr, "HTTP request failed'\n");   
  return -1;
  }
  std::string inp;
  
  std::cout << "Book you want to search?" << std::endl;
  std::cin >> inp;

  std::string url = "https://librivox.org/api/feed/audiobooks/title/" + inp;
  

  curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

  result = curl_easy_perform(curl);
  if (result != CURLE_OK)
  {
    fprintf(stderr, "Error: %s\n", curl_easy_strerror(result));
    return -1;
  }

  curl_easy_cleanup(curl);


  return 0;
} 
