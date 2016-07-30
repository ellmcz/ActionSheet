Pod::Spec.new do |s|
  s.name         = "Sheet"
  s.version      = "1.1"
  s.license      = { :type => 'MIT', :file => 'LICENSE' }
  s.summary      = "sheet控件"
  s.homepage     = "https://github.com/ellmcz/Sheet"
  s.authors      = { "ellmcz" => "wqbs007@163.com" }
  s.source       = { :git => "https://github.com/ellmcz/Sheet.git", :tag =>   "1.1" }
  s.platform     = :ios, '6.0'
  s.requires_arc = true
  s.source_files = 'Sheet/*.{h,m}'
  s.framework = 'UIKit'
end