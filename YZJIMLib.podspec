#
# Be sure to run `pod lib lint YZJIMLib.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'YZJIMLib'
  s.version          = '0.1.4'
  s.summary          = '云之家IMSDK底层库'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
云之家IMSDK底层库 lib层
                       DESC

    s.homepage         = 'https://github.com/yzjMobile/YZJIMLib-iOS'
    # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
    s.license          = { :type => 'MIT', :file => 'LICENSE' }
    s.author           = { 'CloudHub' => 'http://www.yunzhijia.com' }
    s.source           = { :git => 'https://github.com/yzjMobile/YZJIMLib-iOS.git', :tag => s.version.to_s, :submodules => true }
    # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

    s.ios.deployment_target = '8.0'
    # s.static_framework = true
    # s.resource_bundles = {
    #   'YZJIMLib' => ['YZJIMLib/Assets/*.png']
    # }

    s.libraries = 'z', 'resolv.9', 'c++'
    s.frameworks = 'Foundation', 'CFNetwork', 'CoreTelephony', 'SystemConfiguration'
    s.dependency 'AFNetworking'
    s.dependency 'JSONModel'
    s.dependency 'PromiseKit'
    s.dependency 'WCDB.swift'


    s.vendored_frameworks = ['YZJIMLib/Assets/mars.framework', 'YZJIMLib/Assets/YZJIMLib.framework']
    # s.source_files = 'YZJIMLib/Classes/Demo.swift'


end
